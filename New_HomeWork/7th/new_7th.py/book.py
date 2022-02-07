class book:
    def __init__(self, name, year, author, company, genre):
        self.name = name
        self.year = year
        self.author = author
        self.company = company
        self.genre = genre

    def getBook(self):
        return [self.name, self.year, self.author, self.company, self.genre]