#Write a Python program to store students PRNs with date and month of birth. Let List_A and List_B be the two list for two SE Computer divisions. Lists are sorted on date and month. Merge these two lists into third list “List_SE_Comp_DOB” resulting in sorted information about Date of Birth of SE Computer students


from datetime import *
n = int(input("Enter total number of students :"))


class SE_comp:
    def __init__(self, prn_A, list_A, prn_B, list_B, combined_list, dob_A, dob_B, A_dob, B_dob):  # Constructor function
        self.prn_A = prn_A
        self.list_A = list_A
        self.prn_B = prn_B
        self.list_B = list_B
        self.combined_list = combined_list
        self.dob_A = dob_A
        self.dob_B = dob_B
        self.A_dob = A_dob
        self.B_dob = B_dob

    def get_data(self):
        print("Choose option 1 if Division A and choose 2 for division B")
        for i in range(n):
            choice = int(input("Enter your choice: "))
            if choice == 1:
                prn = input("Enter your PRN Number: ")
                birthyear = int(input("Enter year: "))
                birthmonth = int(input("Enter month: "))
                birthday = int(input("Enter day: "))
                d = date(birthyear, birthmonth, birthday)
                self.dob_A.append(d)
                self.prn_A.append(prn)

            else:
                p = input("Enter your PRN Number: ")
                birth_year = int(input("Enter year: "))
                birth_month = int(input("Enter month: "))
                birth_day = int(input("Enter day: "))
                o = date(birth_year, birth_month, birth_day)
                self.dob_B.append(o)
                self.prn_B.append(p)

    def sorting(self):

        while self.dob_A:  # Sorting DOB of Division A
            mini = self.dob_A[0]
            for x in self.dob_A:
                if x < mini:
                    mini = x
            self.list_A.append(mini)
            self.dob_A.remove(mini)

        while self.dob_B:  # Sorting DOB of Division B
            mini = self.dob_B[0]
            for x in self.dob_B:
                if x < mini:
                    mini = x
            self.list_B.append(mini)
            self.dob_B.remove(mini)

    def display_data(self):  # Function for displaying data
        print("\nDetails of A")
        print("DoB\t\t\t PRN")
        A_prns = []
        for i in self.list_A:
            i.strftime("%d %b, %Y")
            dtstring = str(i.strftime("%d %b, %Y"))
            self.A_dob.append(dtstring)
        for y in range(len(self.prn_A)):
            pr = self.prn_A[y]
            A_prns.append(pr)
        for i in range(len(self.A_dob)):
            print(self.A_dob[i], A_prns[i])

        print("\nDetails of B")
        print("DoB\t\t\t PRN")
        B_prns = []
        for i in self.list_B:
            i.strftime("%d %b, %Y")
            _dtstring = str(i.strftime("%d %b, %Y"))
            self.B_dob.append(_dtstring)
        for y in range(len(self.prn_B)):
            _pr = self.prn_B[y]
            B_prns.append(_pr)
        for z in range(len(self.B_dob)):
            print(self.B_dob[z], B_prns[z])

    def combined_sorting(self):  # Defining funtion for part 2
        self.combined_list = []
        temp = [*self.A_dob, *self.B_dob]  # Adding 2 lists
        while temp:  # Sorting the lists
            mini = temp[0]
            for x in temp:
                if x < mini:
                    mini = x
            self.combined_list.append(mini)
            temp.remove(mini)
        print("\nBirthdays of student in college (Combined)")  # Details of Combined List
        for k in self.combined_list:
            print(k)


if __name__ == "__main__":
    p1 = []
    d1 = []
    p2 = []
    d2 = []
    l = []
    doba = []
    dobb = []
    adob = []
    bdob = []
    s = SE_comp(p1, d1, p2, d2, l, doba, dobb, adob, bdob)
    s.get_data()
    s.sorting()
    s.display_data()
    s.combined_sorting()
