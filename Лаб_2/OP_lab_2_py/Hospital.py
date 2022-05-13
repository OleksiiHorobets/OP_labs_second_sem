from Patient import *

class Hospital:
    def __init__(self, patients_lst=[]):
        self.__patients_lst = patients_lst

        self.__recent_patients_lst = []
        self.__fill_recent_patients_lst()

        self.__old_patients_lst = []
        self.__fill_old_patients_lst()

    def display_patients_lst(self):
        print('\n', '-'*10, 'Patients list', '-'*10)
        for i in self.__patients_lst:
            print(i)

    def get_patients_lst(self):
        return self.__patients_lst

    def get_recent_patients_lst(self):
        return self.__recent_patients_lst

    def get_old_patients_lst(self):
        return self.__old_patients_lst

    def console_input_patients_lst(self):
        while True:
            if input("Want to add patient? Enter Y/N") != 'Y':
                break
            values = []
            values.append(input("Enter patient surname: "))
            values.append(input("Enter last visit date: "))
            values.append(input("Enter current appointment date and time (d.m.y h:m format): "))

            self.__patients_lst.append(Patient(values[0], values[1], values[2]))
        self.__fill_recent_patients_lst()
        self.__fill_old_patients_lst()
        self.__write_data_to_file('patientsList.bin', self.__patients_lst)


    def __fill_recent_patients_lst(self):
        for patient in self.__patients_lst:
            if patient.is_recent_patient():
                self.__recent_patients_lst.append(patient)

    def __fill_old_patients_lst(self):
        for patient in self.__patients_lst:
            if not patient.is_recent_patient():
                self.__old_patients_lst.append(patient)

    def __edit_initial_data_file(self):
        edited_patients_lst = []

        for patient in self.__patients_lst:
            if not patient.time_is_up():
                edited_patients_lst.append(patient)
        self.__patients_lst = edited_patients_lst


    def __write_data_to_file(self, file_name, patients_lst ):
       try:
            with open(file_name, 'wb') as file:
                for patient in patients_lst:
                    file.write((patient.get_surname() + '\n').encode())
                    file.write((patient.get_last_visit_date().strftime("%d.%m.%Y")+ '\n').encode())
                    file.write(str(patient.get_appointment_datetime().strftime("%d.%m.%Y %H:%M")+ '\n').encode())
       except:
           print('Error while writing to file', file_name)


    def read_data_from_file(self, file_name):
        try:
            with open(file_name, 'rb') as file:
                values = []
                lines = file.readlines()
                counter = 0
                if len(self.__patients_lst) != 0:
                    self.__patients_lst = []
                for line in lines:
                    values.append(line.decode().strip())
                    counter += 1
                    if counter % 3 == 0:
                        self.__patients_lst.append(Patient(values[0], values[1], values[2]))
                        values = []
            self.__fill_recent_patients_lst()
            self.__fill_old_patients_lst()
        except:
            print('Error while reading from file', file_name)


    def write_data_to_cache(self):
        self.__edit_initial_data_file()
        self.__write_data_to_file('old_patients_list.bin', self.__old_patients_lst )
        self.__write_data_to_file('recent_patients_list.bin', self.__recent_patients_lst)
        self.__write_data_to_file('patientsList.bin', self.__patients_lst)