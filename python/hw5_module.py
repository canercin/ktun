import sqlite3

# Establishing a persistent database connection
database = sqlite3.connect(':memory:')
cursor = database.cursor()

def create_database():
    cursor.execute("CREATE TABLE IF NOT EXISTS user (username, password)")
    database.commit()

def check_login(username, password):
    cursor.execute("SELECT * FROM user WHERE username = ? AND password = ?", (username, password))
    user = cursor.fetchone()
    return user is not None

def register_user(username, password):
    cursor.execute("SELECT * FROM user WHERE username = ?", (username,))
    existing_user = cursor.fetchone()
    if existing_user:
        print("Bu kullanıcı adı zaten mevcut.")
        return
    cursor.execute("INSERT INTO user (username, password) VALUES (?, ?)", (username, password))
    database.commit()

def change_password(username, password):
    cursor.execute("UPDATE user SET password = ? WHERE username = ?", (password, username))
    database.commit()

# Close the database connection when the module is unloaded
def close_database():
    database.close()

def jaccard_similarity(firsttext, secondtext):
    totallength = len(firsttext) + len(secondtext)
    similarcount = 0
    for c in firsttext:
        if c in secondtext:
            similarcount = similarcount + 1
    return float(similarcount) / float(totallength)

def cosine_similarity(firsttext, secondtext):
    firstset = set(firsttext.split())
    secondset = set(secondtext.split())
    intersection = len(firstset.intersection(secondset))
    return intersection / (len(firstset) * len(secondset))