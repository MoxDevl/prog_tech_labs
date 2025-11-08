from typing import List
from sqlalchemy import ForeignKey
from sqlalchemy.orm import DeclarativeBase, Mapped, mapped_column, relationship

class Base(DeclarativeBase):
    pass

class User(Base):
    __tablename__ = 'user_account'

    id: Mapped[int] = mapped_column(primary_key=True)
    username: Mapped[str]

    orders: Mapped[List["Order"]] = relationship(back_populates="user", lazy='select')

    def __repr__(self) -> str:
        user_str = f'User: {self.username}'
        return user_str


class Order(Base):
    __tablename__ = 'order'

    id: Mapped[int] = mapped_column(primary_key=True)
    product_name: Mapped[str]
    product_count: Mapped[int]
    user_id = mapped_column(ForeignKey("user_account.id"))

    user: Mapped[User] = relationship(back_populates="orders")

    def __repr__(self) -> str:
        order_str = f'Product: {self.product_name}, Count: {self.product_count}'
        return order_str
    

# this method has N+1 problem, just an example
def print_user_orders(user: User) -> None:
    print(user)
    
    if user.orders:
        print('Orders:')
        for order in user.orders:
            print('- '+repr(order))