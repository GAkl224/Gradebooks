In order to utilize this Gradebook:

1. create a gradebook object in the driver class 
        ex. Gradebook gradebook;

2. add your students into the gradebook by entering their first and last name, and ID,
         ex. gradebook.addStudent("John", "Donut", "ABC123");

3. now add your assignments. Enter assignment name and total points.
        ex. gradebook.addAssignment("Exam 1", 50);

4. Assign your students grade by entering students ID and thier score
        ex.  gradebook.giveGrade("ABC123", "Exam 1", 45);

5. To see your entire gradebook, utilise the report() method. 
        ex. gradebook.report()

Notes:

If there is no score entered there will be a "-" in its place.


        
