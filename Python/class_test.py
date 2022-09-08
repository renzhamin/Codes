class test:
    def __init__(self,id=10):
        self.id=id
    def display(self):
        print(self.id)

a=test()
test.display(a)

print(a.__dict__)