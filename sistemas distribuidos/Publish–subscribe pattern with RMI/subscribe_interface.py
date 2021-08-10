from subscribe import Subscribe
import Pyro5.api

daemon = Pyro5.server.Daemon()
ns = Pyro5.api.locate_ns()
uri = daemon.register(Subscribe)
ns.register('subscribe.server', uri)
daemon.requestLoop()