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
map='Z'
date1=''
date2=''
modet=0
modep=0
d=0
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
        '-w') wind=1 ;;
        '-h') heigt=1 ;;
        '-m') moist=1 ;;
        '-F') map='F' ;;
        '-G') map='G' ;;
        '-S') map='S' ;;
        '-A') map='A' ;;
        '-O') map='O' ;;
        '-Q') map='Q' ;;
        '-d') d=1 ;;
        '--tab') sorting=3 ;;
        '--abr') sorting=2 ;;
        '--avl') sorting=1 ;;
        '-f');;
        `expr [0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]`)
            if [ d -eq 1 ] ; then
                if [ -z date1 ]; then
                    date1=arg
                else
                    date2=arg
                fi
            else
                echo "Error : Date before -d"
                exit 3
            fi
            ;;
       '-'*) echo -n 'Error : ' & echo -n \'$arg\' & echo ' argument incorrect' & exit 2;;
    esac
done

if [ $temp -eq 0 ] && [ $press -eq 0 ] && [ $wind -eq 0 ] && [ $moist -eq 0 ] && [ $height -eq 0 ] ; then
    echo "Error : missing necessary argument (-t or -p or -w or -m or -h)"
    exit 4
fi

if [ $d -eq 1 ] ; then
    #check if date correct then cut into file with date correct
    echo "lol"
fi


# todo the map thingy later(annoying)
#case $map in
#     F)  ;;
#     G)  ;;
#     S)  ;;
#     A)  ;;
#     O)  ;;
#     Q)  ;;
# esac

# todo later because mode

if [ -e 'temp.csv' ] ; then
    echo "remove temp"
fi
# if [ $temp -eq 1 ] ; then
# fi
# if [ $press -eq 1 ] ; then
# fi



output=0

if [ $wind -eq 1 ] ;then
    cut -f 1,4,5 -d';' $toSort > temp.csv
    make
fi

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
set title 'graphique'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [-180:180]
set yrange [-180:180]
set palette rgb 21,22,23
splot 'output.csv' using 1:2:3 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_moisture.png

fi
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
set title 'graphique'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [-180:180]
set yrange [-180:180]
set palette viridis
splot 'output.csv' using 1:2:3 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_moisture.png


fi






