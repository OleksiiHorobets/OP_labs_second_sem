import datetime


class Patient:
    def __init__(self, surname, last_visit_date, appointment_time ):
        self.__surname = surname
        self.__last_visit_date = datetime.datetime.strptime(last_visit_date, "%d.%m.%Y")
        self.__appointment_datetime = datetime.datetime.strptime(appointment_time, "%d.%m.%Y %H:%M")

    def __str__(self):
        return "Surname: {0}\nLast vist date: {1}\nAppointment date and time: {2}\n".format(self.__surname, self.__last_visit_date.strftime("%d.%m.%Y"), self.__appointment_datetime.strftime("%d.%m.%Y %H:%M"))

    def time_is_up(self):
        return datetime.datetime.now() > self.__appointment_datetime

    def is_recent_patient(self):
        delta_days = datetime.timedelta(10)
        return datetime.datetime.now() - delta_days <= self.__last_visit_date

    def get_surname(self):
        return self.__surname

    def get_last_visit_date(self):
        return self.__last_visit_date

    def get_appointment_datetime(self):
        return self.__appointment_datetime

    def set_surname(self, surname):
        self.__surname = surname

    def set_last_visit_date(self, last_visit_date):
        self.__last_visit_date = last_visit_date

    def set_appointment_datetime(self, appointment_datetime):
        self.__appointment_datetime = appointment_datetime


