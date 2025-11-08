from user_class import Base, User, Order, print_user_orders
from sqlalchemy import create_engine, select
from sqlalchemy.orm import Session, joinedload, selectinload

# db_url = r'sqlite:///src\python\lab7\user.db'
db_url = 'sqlite:///:memory:'
engine = create_engine(db_url,
                       echo=True
)
Base.metadata.create_all(engine)

u1 = User(username='Smart')
u2 = User(username='Dumb')

o1 = Order(product_name='Orthopedic Chair', product_count=2)
o2 = Order(product_name='Gamer Chair', product_count=1)
o3 = Order(product_name='Smart Toster', product_count=1)

u1.orders.append(o1)
u1.orders.append(o3)
u2.orders.append(o2)


with Session(engine) as session:
    session.add_all([u1, u2])
    session.commit()


with Session(engine) as session:
    # stmt = select(Order).options(joinedload(Order.user, innerjoin=True)).order_by(Order.user_id)
    stmt = select(User, Order).join(Order, Order.user_id==User.id).order_by(User.id)
    curr_id=-1
    for row in session.execute(stmt):
        if row.User.id != curr_id:
            curr_id = row.User.id
            print(f'User: {row.User.username}')
            print('Orders:')
        print('- '+repr(row.Order))