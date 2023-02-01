#!/bin/bash
#!/usr/local/bin/gnuplot -persist
RANDOM=$$
nmb_args=$#
outputfile="output.csv"


#write the help
help() {
    echo 'WIP'
    exit 0
}



#check if there is arguments

if [ $nmb_args -eq 0 ] ; then
    echo 'Invalid : no arguments'
    exit 1
fi

# check if the first arg is --help

if [ "$1" = "--help" ] ; then
    help
fi


# check if there is an -f and store de file name
isF=0
toSort=''
for arg in $*; do
    if [ $isF -eq 1 ] ; then
        toSort=$arg
        break
    fi
    if [ $arg = '-f' ] ; then
        isF=1
    fi
done

#check if the file is correct and readable
if [ ! -e $toSort ] || [ ! -f $toSort ] || [ ! -r $toSort ] ; then
    echo 'Error : file does not exist or is not a file or cannot be read'
fi


#handle all the rest of the arguments
temp=0
press=0
wind=0
height=0
moist=0
sorting=0 #originaly to 1(avl) but is necessary to check if there is a double used in arg
date1=''
date2=''
modet=0
modep=0
d=0
coo=""

for arg in $* ;do #not robust yet watch out four double -*
    case $arg in
        '-t'?) temp=1
            if [ arg = '-t1' ] ; then
                modet=1
            elif [ arg = '-t2' ] ; then
                modet=2
            elif [ arg = '-t3' ] ; then
                modet=3
            else
                echo 'Error : -t requiere a mode EX : -t1'
                exit 5
            fi
        ;;
        '-p'?) press=1
            if [ arg = '-p1' ] ; then
                modep=1
            elif [ arg = '-p2' ] ; then
                modep=2
            elif [ arg = '-p3' ] ; then
                modep=3
            else
                echo 'Error : -t requiere a mode EX : -p1'
                exit 5
            fi
        ;;
        '-w') wind=1 d=0 ;;
        '-h') heigt=1 d=0 ;;
        '-m') moist=1 d=0;;
        '-F') coo="F" d=0;;
        '-G') coo="G" d=0;;
        '-S') coo="S" d=0;;
        '-A') coo="A" d=0;;
        '-O') coo="O" d=0;;
        '-Q') coo="Q" d=0;;
        '-d') d=1 ;;
        '--tab') sorting=3 d=0;;
        '--abr') sorting=2 d=0;;
        '--avl') sorting=1 d=0;;
        '-f')d=0;;
        `expr [0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]`)
            if [ d -eq 1 ] ; then
                if [ -z date1 ]; then
                    date1=arg
                else
                    date2=arg
                fi
            else
                echo "Error : Date incorrect placement"
                exit 3
            fi
            ;;
       '-'*) echo -n 'Error : ' & echo -n \'$arg\' & echo ' argument incorrect' & exit 2;;
    esac
done

#check if there is at least one of the necessary sorting arg
if [ $temp -eq 0 ] && [ $press -eq 0 ] && [ $wind -eq 0 ] && [ $moist -eq 0 ] && [ $height -eq 0 ] ; then
    echo "Error : missing necessary argument (-t or -p or -w or -m or -h)"
    exit 4
fi



if [ $d -eq 1 ] ; then
    if (( $date1 > $date2 )) ; then
        echo "Error : interval of dates invalid"
        exit 6
    fi
    if (( $date1 < "2010-01-05" )) || (( $date2 > "2022-01-25")); then
        echo "Error : date invalid"
        exit 7
    fi
    echo "lol"
fi

xmin=0
xmax=0
ymin=0
ymax=0
# todo the map thingy later(annoying)
if [ ! -z $coo ] ; then
    case $coo in
    '-F') xmin=-4 xmax=8 ymin=42 ymax=51 ;;
    '-G') xmin= xmax= ymin= ymax= ;;
    '-S') xmin= xmax= ymin= ymax= ;;
    '-A') xmin= xmax= ymin= ymax= ;;
    '-O') xmin= xmax= ymin= ymax= ;;
    '-Q') xmin= xmax= ymin= ymax= ;;
    esac
fi

# todo later because mode

#gnuplot -t

if [ $temp -eq 1 ] ; then
    case $modet in
    1)  cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode1.gnu "temperature"
        ;;
    2)cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode2.gnu "temperature";;
    3)cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode3.gnu "temperature";;
    esac
fi


#gnuplot -p

if [ $press -eq 1 ] ; then
    case $modep in
    1)  cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode1.gnu "pression"
        ;;
    2)cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode2.gnu "pression";;
    3)cut -f ?,?,?,? -d";" $toSort > temp.csv
        make
#       ./file
        gnuplot -p -c mode3.gnu "pression";;
    esac
fi



output=0


#gnuplot -w

if [ $wind -eq 1 ] ;then
    cut -f 1,4,5 -d';' $toSort > temp.csv
#     make
    echo "set terminal png size 400,300 enhanced font default
set output 'output.png'
unset key
set grid
set title 'graphique des vents'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [-180:180]
set yrange [-180:180]
plot 'output.csv' using 1:2:($3):($4) with vectors head size 0.5,20
">map.gnu
    gnuplot -p -c map.gnu
    mv output.png vectormap_wind.png
fi

#gnuplot -m

if [ $moist -eq 1 ] ; then
    cut -f 6,10 -d';' $toSort > temp.csv
#     make
    if [ -e "map.gnu" ] ; then
        rm map.gnu
    fi
        echo "set terminal png size 400,300 enhanced font default
set output 'output.png'
set view map
unset key
set pm3d
set dgrid3d 100,100
set pm3d interpolate 0,0
set title 'graphique d'humidité'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [-180:180]
set yrange [-180:180]
set palette rgb 21,22,23
splot 'output.csv' using 1:2:3 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_moisture.png
#    ./lecode temp.csv m 1
fi


#gnuplot -h

if [ $height -eq 1 ] ; then
    cut -f 10,14 -d';' $toSort > temp.csv
    make
#     ./lecode temp.csv h 1
    if [ -e "map.gnu" ] ; then
        rm map.gnu
    fi
        echo "set terminal png size 400,300 enhanced font default
set output 'output.png'
set view map
unset key
set pm3d
set dgrid3d 100,100
set pm3d interpolate 0,0
set title 'graphique d'altitude'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [-180:180]
set yrange [-180:180]
set palette viridis
splot 'output.csv' using 1:2:3 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_height.png
fi





