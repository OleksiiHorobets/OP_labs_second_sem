from Patient import *
from Hospital import *


def run(hos):
    print("--------------MENU--------------")
    print("<1>. Create patients list using console input")
    print("<2>. Get patients list data from file" )
    ans = input()
    if ans == '1':
        hos.console_input_patients_lst()
    elif ans == '2':
        hos.read_data_from_file(input("Enter file name: "))
    else:
        print('Wrong input!')
        return 0

    hos.display_patients_lst()
    hos.write_data_to_cache()

if __name__ == '__main__':
    # p1 = Patient("Johnson", "28.04.2022", "02.05.2022 20:05")
    # p2 = Patient("Anderson", "25.03.2022", "20.05.2022 21:30")
    # p3 = Patient("Madison", "23.02.2021", "20.05.2022 10:30")
    # p4 = Patient("Heisenberg", "10.07.2020", "21.05.2022 11:30")
    # p5 = Patient("Stevenson", "11.05.2022", "20.05.2022 14:30")
    # Hospital([p1, p2, p3, p4, p5]).write_data_to_cache()

    hos = Hospital()

    run(hos)


