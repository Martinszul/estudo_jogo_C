# 🏎️ Car Survival Game em C com OpenGL (FreeGLUT)

Um jogo de desviar de carros top-down desenvolvido em C utilizando OpenGL e FreeGLUT, com sprites desenhados manualmente em matrizes de pixels, sistema de pontuação crescente, ranking (Top 5 melhores), tela de Game Over e mecânicas de colisão com obstáculos e coletáveis.

## Mecânica do Jogo

O jogador controla um carro vermelho em uma pista top-down e deve sobreviver o máximo possível enquanto:

- Desvia de 4 carros adversários que percorrem a pista em diferentes velocidades
- Coleta galões de gasolina espalhados pela pista para recuperar vidas
- Perde automaticamente vida a cada 1,5 segundo

O jogo termina quando o jogador perde todas as vidas. Ao final, é exibida uma tela de Game Over com o ranking dos 5 melhores jogadores.

## Obstáculos

- 🟡 Amarelo — desce pela pista, causa -2 vidas
- 🟢 Verde — desce pela pista, causa -3 vidas
- 🔵 Azul — sobe pela pista, causa -3 vidas
- 🟣 Rosa — sobe pela pista, causa -2 vidas

## Coletável

- ⛽ Galão de Gasolina — recupera +1 vida e reaparece em posição aleatória

## Sistema de Vidas

- O jogador começa com 5 vidas
- 1 vida é perdida automaticamente a cada 1,5 segundo
- Colisões com obstáculos reduzem vidas adicionalmente
- Coletar gasolina recupera +1 vida
- Ao chegar em 0 vidas, o jogo encerra

## Sistema de Pontuação

- A pontuação aumenta +1 ponto a cada 100ms enquanto o jogador estiver vivo
- Ao fim da partida, o score é salvo automaticamente em `Scoreboard.txt`
- O jogo mantém um ranking com os 5 melhores de todos os jogadores
- Na tela de Game Over, o jogador atual é destacado no ranking

## Controles

- `W` → ⬆️ Mover para cima
- `S` → ⬇️ Mover para baixo
- `A` → ⬅️ Mover para esquerda
- `D` → ➡️ Mover para direita
- `R` → 🔄 Reiniciar (após Game Over)

## Tela de Game Over

Ao perder todas as vidas, é exibida uma tela contendo:

- Pontuação final da partida
- Ranking com os Top 5 melhores recordes
- Destaque visual para o jogador atual
- Instrução para reiniciar com a tecla `R`

## Autores

Arthur Martins Zulato Moreira e Gabriel Landim Marcelino
