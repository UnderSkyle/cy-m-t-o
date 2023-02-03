# The Weather Analysis
Hello, this project was made for CY Tech by Simon and Charles.
This project will make you able to observe weather data collected from 2010-2022 in multiple graphes. Each graphe will present a certain amount of elements
that have been saved over the years. Theses elements are " altitude, humidity, atmospherique pressure , tempurature and wind speeds". Each of these elements are linked to certains stations located all around the earth ( France, French Guyanna, Saint pierre et Miquelon, Antilles , indian ocean and the antartic). The goal of this project is to be able to filter the data from a source file and sort them accordingly to the users needs to be finally be able to show graphes illustrating the evolution of each element.

how to compile:
download the csv file of the project and put it in the same directory.
chmod +x shell.sh
./shell.sh -f THE_FILE (-m,-h,-w,-p1,-t1) (the others do not work)
or 
./shell.sh --help

How to use our project :

1) You'll need to choose the element that you want to see
2) Then you must choose the area from the list of countries/ocean/continent ( if no area is choosen , every element will be taken into account)
3) You will next need to choose which type of filtering method you want (fusion, abr or avl)
4) Our project will send you back a graph with the sorted element you wanted to see (the way the elements are sorted depends from element to element)


WARNING : the programm C compile but does not fully work so i asked some other group to give me sorted data that i used to create the png
