import hw2_module as mod

text = input("Lütfen bir metin girin: ")

text = mod.dePunc(text)

text = mod.toLower(text)

freq, len = mod.calcFreq(text)

mod.printData(freq, len)

mod.forMe()

