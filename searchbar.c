import SwiftUI

struct Searchbar: View {
    @State private var searchText = "" //Cria uma variável reativa que armazena o texto digitado na barra de busca.
    

       var body: some View {//Define a interface visual da tela.
           NavigationStack { //Cria uma pilha de navegação com barra de título e suporte a navegação entre telas.
               Text("Searching for \(searchText)")//Mostra o texto digitado dinamicamente na tela.
           }
           .searchable(text: $searchText)//Adiciona uma barra de busca ligada à variável searchText.
       }
}
//implementar dps dos cards
#Preview {
    Searchbar()
}
