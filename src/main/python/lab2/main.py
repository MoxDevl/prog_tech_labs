from person import Person
from animals import Cat, Dog

plump_cat = Cat(1, 'Tostada')
smart_dog = Dog(12, 'Arron')


student1 = Person('Mike', plump_cat)
student2 = Person('Kork', smart_dog)

student1.getCompanionInfo()
student2.getCompanionInfo()