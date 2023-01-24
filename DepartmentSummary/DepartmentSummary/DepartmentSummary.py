import mysql.connector
from tabulate import tabulate
try:

    connection = mysql.connector.connect(
    host="localhost",
    user="root",
    password="IdanMaoz",
    database="departmentsummary")
    sql_select_Query = """select d.name as department_name, COUNT(e.ID)  as count_employees   
                          from employee e right join department d on e.dept_id=d.ID 
                          GROUP BY d.name 
                          ORDER BY COUNT(e.ID) desc, d.name """
    cursor = connection.cursor()
    cursor.execute(sql_select_Query)
    # get all records
    records = cursor.fetchall()
    print(tabulate(records, headers=['department_name', 'count_employees'], tablefmt='psql'))
except mysql.connector.Error as e:
    print("Error reading data from MySQL table", e)
finally:
    if connection.is_connected():
        connection.close()
        cursor.close()
        print("MySQL connection is closed")


