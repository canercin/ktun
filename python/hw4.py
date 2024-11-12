import sqlite3


def jaccard(firsttext, secondtext):
    totallength = len(firsttext) + len(secondtext)
    similarcount = 0
    for c in firsttext:
        if c in secondtext:
            similarcount = similarcount + 1
    return float(similarcount) / float(totallength)


database = sqlite3.connect(':memory:')
cursor = database.cursor()
cursor.execute("CREATE TABLE IF NOT EXISTS text (text)")
cursor.execute("INSERT INTO text VALUES ('text')")
cursor.execute("INSERT INTO text VALUES ('text')")
database.commit()
result = cursor.execute("SELECT * FROM text").fetchall()
database.close()
textList = []
for row in result:
    textList.append(row[0])

score = jaccard(textList[0], textList[1])
print("Jaccard score = ", score)
file = open("score.txt", "w")
file.write(str(score))
file.close()
