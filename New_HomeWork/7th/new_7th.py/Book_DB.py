from operator import ge


class Book_DB:
    def __init__(self, title, author, year, company, genre): # 생성자
        self.title = title
        self.author = author
        self.year = year
        self.company = company
        self.genre = genre
        
    