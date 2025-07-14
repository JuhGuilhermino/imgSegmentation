# Segmentação de Imagens PPM com Algoritmos de Fluxo Máximo/Corte Mínimo

Este projeto implementa algoritmos de fluxo máximo aplicados à segmentação de imagens com base em grafos. A segmentação é feita usando sementes definidas pelo usuário e técnicas  Ford-Fulkerson, Push-Relabel e Boykov-Kolmogorov. Ele inclui ainda uma análise comparativa do desempenho desses algortimos em função do tempo de execução

## 🖼️ Exemplo de Segmentação

| Original                | Segmentada              |
|-------------------------|-------------------------|
| ![original](imgs/test.ppm) | ![segmentada](imgs/new.ppm) |

---

## 🚀 Como executar

1. Clone o repositório;
2. Digite no terminal dentro da pasta do projeto:
    1.1 `make` - para gerar executável.
    1.2 `./main [algoritmo] [path da imagem]` - para rodar.

```bash

---

## ✅ Checklist de Implementação

- [x] Leitura da imagem
- [x] Escrita da imagem
- [ ] Calculo dos pesos baseado nas sementes
- [ ] Segmentação
    - [ ] Ford-Fulkerson
    - [ ] Boykov-Kolmogorov (BK)
    - [ ] Push-Relabel (em desenvolvimento)
- [ ] Cáluclo do tempo
- [ ] Sofisticação dos testes

---

## 👩‍💻 Autoria

 **Júlia Guilhermino**  
Estudante e pesquisadora interessada em algoritmos de grafos e visão computacional.  
GitHub: [@JuhGuilhermino](https://github.com/JuhGuilhermino)





