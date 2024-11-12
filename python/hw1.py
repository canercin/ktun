# Kullanıcıdan metin al
text = input("Lütfen bir metin girin: ")

# Metinde bulunan noktalama işaretlerini kaldır
punctuation = [".", ",", ";", ":", "!", "?", "'", "\"", "(", ")", "[", "]", "{", "}", "<", ">"]
for punct in punctuation:
    text = text.replace(punct, "")

# Metni küçük harflere çevir
text = text.lower()

# Metnin uzunluğunu al
length = len(text)

# Saklanacak sözlük yapısını oluştur
frequency_analysis = {}

# Sözlüğe her bir harfi ata ve oranını hesapla
for char in text:
    if char.isalpha():  # Sadece alfabetik karakterleri işle
        frequency_analysis[char] = frequency_analysis.get(char, 0) + 1

# Sonuçları ekrana yazdır
print("Harf Frekansları:")
for char, frequency in sorted(frequency_analysis.items()):
    ratio = frequency / length * 100  # Oranı hesapla
    print(f"{char}: {frequency} ({ratio:.2f}%)")


