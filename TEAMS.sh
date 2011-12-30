#! /bin/bash
######## Terminal Effects And Manipulation Script (T.E.A.M.S) ########
echo "------------------------------------------------ "
echo "| Terminal Effects And Manipulation Script 1.0 |"
echo "|                                              |"
echo "|           By: Anthony Hopkins                |"
echo "------------------------------------------------"
sleep 3
echo " "
echo -n "Please pick a terminal background color from the following options: (blue, yellow, red)"
read -e COLOR
setterm -background $COLOR
echo "Thank you for using my script. If you have any issues running it, fuck you!"

