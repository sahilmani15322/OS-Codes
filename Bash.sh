while :
do

echo "+--------Student  Database--------+";
echo "|    1: Insert a New Record       |";
echo "|    2: Display All               |";
echo "|    3: Search a Record           |";
echo "|    4: Modify a Record           |";
echo "|    5: Delete a Record           |";
echo "|    6: Exit                      |";
echo "+---------------------------------+";

echo -n " Enter choice : ";
read ch;

case $ch in
	1)	touch sahil.txt
		echo -n "Enter Name :: ";
		read name;
		echo -n "Enter Roll No :: ";
		read rno;
		echo -n "Enter Regno :: ";
		read regno;
		echo -n "Enter Branch :: ";
		read branch;
		$(echo $regno  $rno  $name  $branch >> sahil.txt)
		;;

	2)      echo "Reg_No--Roll_no--Name--Branch";
		cat sahil.txt;
		;;

	3)	echo -n "Enter Regno : ";
		read reg;
		if grep -q  "^$reg" sahil.txt; then
			grep -w "^$reg" sahil.txt;

		else
			echo  "Record not found.";
		fi		
		;;

	4)
		cat sahil.txt
		read -p "Enter the line no to modify" n1
		read -p "Enter New Rollno ::" rno
		read -p "Enter New Name ::" name
		read -p "Enter New Reg No. ::" regno
		read -p "Enter New Branch ::"  branch
	 	sed -i "$n1 s/.*/$regno  $rno  $name  $branch/"  sahil.txt
		echo "Updated SUCCESSFULLY"
		;;

	5)	echo -n "Enter Regno ::";	
		read reg;
		if grep -q "^$reg " sahil.txt; then
			grep -v "^$reg" sahil.txt > newdb.txt;
			mv newdb.txt sahil.txt
			echo "Record Deleted!!!!";
		
		else
			echo "Record not found!!!!";
		fi
		;;
       
	6) exit ;;

	*) 	echo -n "Wrong Choice!!!!";
		;;
esac
done

