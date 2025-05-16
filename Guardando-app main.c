import SwiftUI
import SwiftData

struct ContentView: View {
    
       var body: some View {
           Searchbar()
          
   }
//cards horizontais


#Preview {
    ContentView()
       .modelContainer(for: Item.self, inMemory: true)
}
