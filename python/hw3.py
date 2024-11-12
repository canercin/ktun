# personel sınıfı
class Personel:
    # personel sınıfının constructor'ı
    def __init__(self, name, departman, expYear, salary):
        self.name = name
        self.departman = departman
        self.expYear = expYear
        self.salary = salary

    # personelin bilgilerini yazdıran fonksiyon
    def dataPrinter(self):
        print("Personel Adı:", self.name)
        print("Çalıştığı Departman:", self.departman)
        print("Çalışma Yılı:", self.expYear)
        print("Maaşı:", self.salary)


# şirket sınıfı
class Company:
    # şirket sınıfının constructor'ı
    def __init__(self):
        self.list = []

    # personel ekleme
    def addpersonel(self, personel):
        self.list.append(personel)

    # personellerin bilgilerini yazdırma
    def listallpersonel(self):
        for personel in self.list:
            personel.dataPrinter()

    # personelin maaşını günceller
    def raisesalary(self, personelname, zam):
        for personel in self.list:
            if personel.name == personelname:
                personel.salary = personel.salary + (personel.salary * zam)

    # personelin ilişiğinin kesilmesi halinde listeden silinmesi
    def layoff(self, personelname):
        for personel in self.list:
            if personel.name == personelname:
                self.list.remove(personel)
                break
            else:
                print("personel bulunamadı")


sirket = Company()

# personel ekleme
personel1 = Personel("Ahmet", "İnsan Kaynakları", 3, 5000)
personel2 = Personel("Ayşe", "Finans", 5, 6000)

sirket.addpersonel(personel1)
sirket.addpersonel(personel2)

# personel listeleme
print("Şirketin Personel Listesi:")
sirket.listallpersonel()

# personel maaşına zam yapma
sirket.raisesalary("Ahmet", 0.1)  # %10 zam yapalım

# güncel listeyi yazdırma
print("\nMaaş zammı yapıldıktan sonraki Personel Listesi:")
sirket.listallpersonel()

# personeli işten çıkarma 
sirket.layoff("Ayşe")

# güncel listeyi yazdırma
print("\nPersonel çıkartıldıktan sonraki Personel Listesi:")
sirket.listallpersonel()
