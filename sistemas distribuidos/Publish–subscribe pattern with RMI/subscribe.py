import Pyro5.api

@Pyro5.api.expose
class Subscribe():

    def __init__(self):
        self._category = ''
        self._publish = ''

    @property
    def __categorias(self):
        categories_file = open('category.txt', 'r')
        category_list = []

        for line in categories_file:
            category_list.append(line.strip())

        categories_file.close()

        return category_list

    def __load_publisher(self, category):
        publications_file = open(category, 'r')
        publications_list = []

        for line in publications_file:
            publications_list.append(line.strip())

        publications_file.close()

        return publications_list


    def load_new_publications(self, category):
        self._category = category.strip()
        set_categories = self.__categorias
        if self._category in set_categories:
            itens = self.__load_publisher(self._category)
            return itens
        else:
            print('categoria não existente')


