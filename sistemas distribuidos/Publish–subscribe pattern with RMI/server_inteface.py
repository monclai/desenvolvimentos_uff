from publisher import Publish_server
import Pyro5.api


daemon = Pyro5.server.Daemon()
ns = Pyro5.api.locate_ns()
uri = daemon.register(Publish_server)
ns.register('publisher.server', uri)
daemon.requestLoop()