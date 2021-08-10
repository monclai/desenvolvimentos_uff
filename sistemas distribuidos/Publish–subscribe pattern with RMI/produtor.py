import Pyro5.api


publicacao = Pyro5.api.Proxy('PYRONAME:publisher.server')

categoria = str(input('Entre com uma categoria: ')).strip()
categoria.lower()

texto = str(input('Entre com a informação: ')).strip()
texto.lower()

publicacao.category(categoria)
publicacao.publisher(texto)



categoria = str(input('Entre com uma categoria: ')).strip()
categoria.lower()

texto = str(input('Entre com a informação: ')).strip()
texto.lower()

publicacao.category(categoria)
publicacao.publisher(texto)
