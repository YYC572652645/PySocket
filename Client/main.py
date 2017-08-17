
from client import Client
import globaldef

if __name__ == '__main__':

    for i in range(0, 10000):
        client = Client()
        client.connServer()