import subprocess

def run_program(page_size, num_iterations):
    command = f"./programa {page_size} {num_iterations}"
    output = subprocess.check_output(command, shell=True).decode("utf-8")
    avg_time = float(output.strip().split(": ")[1])
    return avg_time

def main():
    page_sizes = range(1, 1001)  # Tamanhos de página de 1 até 1000
    num_iterations = 10000
    results = {}

    for page_size in page_sizes:
        avg_time = run_program(page_size, num_iterations)
        results[page_size] = avg_time

    # Imprime os resultados
    for page_size, avg_time in results.items():
        print(f"Tamanho da página: {page_size}, Tempo médio por acesso: {avg_time:.2f} ms")

if __name__ == "__main__":
    main()
