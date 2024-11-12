def dePunc(text):
    # Metinde bulunan noktalama işaretlerini kaldır
    punctuation = [".", ",", ";", ":", "!", "?", "'", "\"", "(", ")", "[", "]", "{", "}", "<", ">"]
    for punct in punctuation:
        text = text.replace(punct, "")
    return text

def toLower(text):
    # Metni küçük harflere çevir
    return text.lower()

def calcFreq(text):
    # Metnin uzunluğunu al
    length = len(text)
    # Saklanacak sözlük yapısını oluştur
    frequency_analysis = {}
    # Sözlüğe her bir harfi ata ve oranını hesapla
    for char in text:
        if char.isalpha():  # Sadece alfabetik karakterleri işle
            frequency_analysis[char] = frequency_analysis.get(char, 0) + 1
    return frequency_analysis, length

def printData(frequency_analysis, length):
    print("Harf Frekansları:")
    for char, frequency in sorted(frequency_analysis.items()):
        ratio = frequency / length * 100  # Oranı hesapla
        print(f"{char}: {frequency} ({ratio:.2f}%)")

def forMe():
    print("Caner Çin")
    print("211213052")
    print("Hayırlı Ramazanlarr..")