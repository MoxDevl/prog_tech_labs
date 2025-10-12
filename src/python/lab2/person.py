from animal_base import IAnimal
from animals import Cat, Dog


class Person():
    def __init__(self, name: str, companion: IAnimal):
        self._name = name
        self._companion = companion

    def getCompanionInfo(self) -> None:
        plural_letter = '' if self._companion.getAge()==1 else 's'
        seperator = '-------------------'
        
        print(seperator)
        print(
f'''Companion for {self._name} is named {self._companion.getName()}
It is {self._companion.getAge()} year{plural_letter} old
And it sounds like this'''
        )
        self._companion.makeSound()
        print(seperator)