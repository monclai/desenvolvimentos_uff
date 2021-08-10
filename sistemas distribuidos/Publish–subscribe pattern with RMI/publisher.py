import Pyro5.api

@Pyro5.api.expose
class Publish_server():

    def __init__(self):
        self._category = ''
        self._publisher = ''

    @property
    def __categorias(self):
        categories_file = open('category.txt', 'r')
        category_list = []

        for line in categories_file:
            category_list.append(line.strip())

        categories_file.close()

        return category_list

    def __add_category_and_publisher(self, category, term):
        #adiciona no arquivo category.txt
        categories_file = open('category.txt', 'a')
        input_category = category+'\n'
        categories_file.write(input_category)
        categories_file.close()        
        
        #cria um novo arquivo e adiciona novo valor
        publiser_file = open(category, 'w')
        input_term = term+'\n'
        publiser_file.write(input_term)
        publiser_file.close()

    def __append_new_publisher(self, category, term):
        publiser_file = open(category, 'a')
        input_term = term+'\n'
        publiser_file.write(input_term)
        publiser_file.close()

    def category(self, new_category):
        self._category = new_category.strip()

    def publisher(self, new_term):
        self._publisher = new_term.strip()
        categories = self.__categorias
        if (self._category in categories):
            self.__append_new_publisher(self._category, self._publisher)
        else:
            self.__add_category_and_publisher(self._category, self._publisher)




       
        
