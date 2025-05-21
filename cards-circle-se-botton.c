//
//  CardsCircleView.swift
//  Challenge-04
//
//  Created by Keitiely Silva Viana on 20/05/25.
//

import SwiftUI

struct CardsCircleView: View {
    
    let rows = [GridItem(.fixed(100))] // linha da grade, altura fixa de 100 pontos
    
    let icones: [String] = [ //array de strings com o nome dos icones sf e os meus vetores
        "cup.and.heat.waves.fill",
        "fork.knife",
        "Pao",
        "Panela",
        "wineglass.fill"
    ]
    
    let nomes: [String] = [ //array de strings com nome abaixo dos circulos
        "Café da manhã",
        "Almoço",
        "Lanche",
        "Jantar",
        "Bebidas"
    ]//falta fazer sobremesa!!
    
    var body: some View {
        VStack(alignment: .leading) {//inico Vstack alinhando a esquerda
            
            ScrollView(.horizontal, showsIndicators: false){ //inicio scroll horizontal
                LazyHGrid(rows: rows, alignment: .center, spacing: 15) {//inicio da grade horizontal
                    ForEach(Array(zip(icones, nomes)), id: \.0) { icone, nome in//for pecorrendo por icone e nomes
                        VStack(spacing: 8) {//incio VStack com espaço do circle para o nome de 8 pontos
                            
                            Circle()//desenhando o circulo
                                .fill(Color.azulCardsCircle)
                                .frame(width: 60, height: 60)
                            
                                .overlay(//usado para por algo em cima, imagem, icone, texto..
                                    Group {
                                        //se icone for sf symbol exibe
                                        if UIImage(systemName: icone) != nil {
                                            Image(systemName: icone)
                                                .font(.system(size: 26))
                                        } else {//se nao, carrega imagem da assets
                                            Image(icone)
                                                .resizable()//redimensiona imagem
                                                .scaledToFit()//ajuste para caber proporcionalmente no frame
                                        }//fim else
                                    }//fim group
                                    
                                    //definindo tamanho e cor do icone
                                        .frame(width: 30, height: 30)
                                        .foregroundColor(.iconeCardCircle)
                                    
                                )//fim overlay
                            
                            Text(nome)//definindo texto e cor do texto abaixo do circulo
                                .font(.system(size: 10, weight: .bold, design: .rounded))
                                .foregroundColor(.iconeCardCircle)
                        }//fim VStack
                        
                        .frame(width: 90)//largura fixa para cada card vertical do circulo com texto
        
                    }//fim For
                }//fim grade
                .padding(.horizontal)//espaço horizontal interno da grade
            }//fim scroll
            .frame(height: 100)//altura fixa para scroll horizontal
        }//fim VStack
        .padding()//padding geral ao redor da vstack
    }//fim body
}//fim sruct

#Preview {
    CardsCircleView()
}
