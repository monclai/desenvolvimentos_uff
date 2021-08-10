import Pyro5.api

sub = Pyro5.api.Proxy('PYRONAME:subscribe.server')

topico = str(input('Digite o topico: ')).strip()

valores = sub.load_new_publications(topico)
print(valores)
