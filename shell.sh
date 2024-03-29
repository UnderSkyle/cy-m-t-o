#!/bin/bash
#!/usr/local/bin/gnuplot -persist
RANDOM=$$
nmb_args=$#
outputfile="output.csv"


#write the help
help() {
    echo 'Usage : ls[OPTION]...[FILE]...
Giving specific details of the files (from the present directory by default).
Filtered by Alphébetical order if the options -cftuvSUX or –sort are in usage.


The arguments you have to use for longer options are the same for the shorter ones.


-f<name_of_file>,-- input file                                 unavoidable option        


-d<min><max>,-- dates                                format of the dates                                                                                YYYY-MM-DD
-h, -- altitude                                                 will show the altitude of each station.
they will be sorted by descending order
-h, -- humidity                                                 will show the maximum humidity
recorded per station. They will be sorted by descending order
-p1, -- atmospheric pressure                                will show the minimum, maximal and                                                                                                                                                                          average pressure of each station.
                                                        The stations will be sorted by ascending                                                         order.
-p2,-- atmospheric pressure                                 Stations will show the average pressure                                                          per day and hour.                            
                                                        will be sorted by chronological order
-p3,-- atmospheric pressure                                will show the pressure per day and hour.
                                                        Stations will be sorted by chronological ,                                                         then by ascending order.
-t1,-- temperature                                         will show the minimum, maximal and                                                                                                                                                                          average temperature of each station.
The stations will be sorted by ascending
order.
-t2,-- temperature                                         will show the average tempeature                                                                  per day and hour per station.                            
                                                        will be sorted by chronological order        
-t3,--temperature                                         will show the temperature per day/hour.
                                                        Stations will be sorted by chronological ,                                                         then by ascending order.
-w,-- wind                                                 will show the average orientation and                                                         speed per Station.
                                                        the stations will be sorted by ascending                                                         order
types of locations : 


-F,-- France                                                one of the locations available for data
-G,-- French Guiana                                        one of the locations available for data
-S,-- Saint-Pierre et Miquelon                         one of the locations available for data
-A,-- Antilles                                                 one of the locations available for data
-O,-- Indien Ocean                                         one of the locations available for data
-Q,-- Antarctica                                        one of the locations available for data 


types of filters


-tab,-- tab                                                Filter program that uses fusion with a                                                         a linear structure
-abr,-- abr                                                 Filter program that uses tree structure                                                        with recherche mechanism
-avl,-- avl                                                Filter program that uses tree structure                                                        with a recherche mechanism and auto                                                        balancing mechanisms 


Condition of exit : 
0                in case of succesful
1                in case of minor issues (like impossible to acces the sup folder)
2                in case of major issues ( like impossible to acces an argument from a ligne of                                            commande).'
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
test=`head -c 2 $toSort`
test2="ID"
if [ "$test" == "$test2" ] ; then
    echo 'hello'
    sed 1d $toSort > "meteo_data.csv"
    toSort="meteo_data.csv"
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
            if [ $arg = '-t1' ] ; then
                modet=1
            elif [ $arg = '-t2' ] ; then
                modet=2
            elif [ $arg = '-t3' ] ; then
                modet=3
            else
                echo 'Error : -t requiere a mode EX : -t1'
                exit 5
            fi
        ;;
        '-p'?) press=1
            if [ $arg = '-p1' ] ; then
                modep=1
            elif [ $arg = '-p2' ] ; then
                modep=2
            elif [ $arg = '-p3' ] ; then
                modep=3
            else
                echo 'Error : -p requiere a mode EX : -p1'
                exit 5
            fi
        ;;
        '-w') wind=1 d=0 ;;
        '-h') height=1 d=0 ;;
        '-m') moist=1 d=0;;
        '-F') cat $toSort | awk -F ';' '{if($1 >= 7005 && $1 <= 7790) print $0}' > tempReg.csv $toSort = tempReg.csv d=0;;
        '-G') cat $toSort | awk -F ';' '{if($1 >= 81401 && $1 <= 81415) print $0}'> tempReg.csv $toSort = tempReg.csv  d=0;;
        '-S') cat $toSort | awk -F ';' '{if($1 == 71805) print $0}'> tempReg.csv $toSort = tempReg.csv  d=0;;
        '-A') cat $toSort | awk -F ';' '{if($1 >= 78890 && $1 <= 78925) print $0}'> tempReg.csv $toSort = tempReg.csv  d=0;;
        '-O') cat $toSort | awk -F ';' '{if($1 >= 61968 && $1 <= 67005) print $0}'> tempReg.csv $toSort = tempReg.csv  d=0;;
        '-Q') cat $toSort | awk -F ';' '{if($1 == 89642) print $0}'> tempReg.csv $toSort = tempReg.csv  d=0;;
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
    echo "Date not working yet"
fi

xmin=0
xmax=0
ymin=0
ymax=0


# todo later because mode

#gnuplot -t

if [ ! -e $toSort ] ; then
    echo 'non'
    exit 9
fi

if [ $temp -eq 1 ] ; then
    case $modet in
    1)
#         cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
# #       ./file
        gnuplot -p -c mode1t.gnu "temperature"
        ;;
#     2)
#         cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
#       ./file
#         gnuplot -p -c mode2t.gnu "temperature";;
#     3)cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
# #       ./file
#         gnuplot -p -c mode3.gnu "temperature";;
    esac
fi


#gnuplot -p

if [ $press -eq 1 ] ; then
    case $modep in
    1)
#         cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
#       ./file
        gnuplot -p -c mode1.gnu "pression"
        ;;
#     2)
#         cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
#       ./file
#         gnuplot -p -c mode2.gnu "pression";;
#     3)cut -f ?,?,?,? -d";" $toSort > temp.csv
#         make
#        ./file
#         gnuplot -p -c mode3.gnu "pression";;
    esac
fi



output=0


#gnuplot -w

if [ $wind -eq 1 ] ;then
#     cut -f 1,4,5 -d';' $toSort > temp.csv C doesn't work so use the files given by Maxime Pauchon
#     make
    gnuplot -p -c mapwind.gnu
    mv output.png vectormap_wind.png
fi

#gnuplot -m

if [ $moist -eq 1 ] ; then
#     cut -f 6,10 -d';' $toSort > temp.csv C doesn't work so use the files given by Maxime Pauchon
#     make
#    ./exec m 1
    if [ -e "map.gnu" ] ; then
        rm map.gnu
    fi
        echo "set terminal png size 400,300 enhanced font default
set output 'output.png'
set view map
unset key
set pm3d
set dgrid3d 500,500
set pm3d interpolate 0,0
set title 'graphique humidité'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [*:*]
set yrange [*:*]
set palette rgb 21,22,23
splot 'ordereddatam' using 4:3:2 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_moisture.png
fi


#gnuplot -h

if [ $height -eq 1 ] ; then
#     cut -f 14,10 -d';' $toSort > temp.csv C doesn't work so use the files given by Maxime Pauchon
#     make
#     ./exec m 2
    if [ -e "map.gnu" ] ; then
        rm map.gnu
    fi
        echo "set terminal png size 400,300 enhanced font default
set output 'output.png'
set view map
unset key
set pm3d
set dgrid3d 500,500
set pm3d interpolate 0,0
set title 'graphique altitude'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [*:*]
set yrange [*:*]
set palette rgb 33,15,10
splot 'ordereddatah' using 4:3:2 with pm3d">map.gnu
    gnuplot -p -c map.gnu
    mv output.png heatmap_height.png

fi

# rm temp*.csv




