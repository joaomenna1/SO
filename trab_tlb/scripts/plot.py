import sys
import matplotlib.pyplot as plt

def plot_results(file_path):
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                page_size, avg_time = line.split(",")
                data.append((int(page_size), float(avg_time)))

    page_sizes, avg_times = zip(*data)
    plt.plot(page_sizes, avg_times)
    plt.xlabel("Número de Páginas")
    plt.ylabel("Tempo Médio por Acesso (ms)")
    plt.title("Resultado do Programa")
    plt.show()

def main():
    if len(sys.argv) < 2:
        print("Uso: python script.py <arquivo_de_saida>")
        return

    output_file = sys.argv[1]
    plot_results(output_file)

if __name__ == "__main__":
    main()
