import os

# Lista de carpetas
carpetas = [
    "01Lab10_2024_2_20203361_Valentin_James",
    "02Lab10_2024_1_20203361_Valentin_James",
    "03Lab10_2023_2_20203361_Valentin_James",
    "04Lab10_2025_1_20203361_Valentin_James"
]

# Crear carpetas
for carpeta in carpetas:
    os.makedirs(carpeta, exist_ok=True)

print("✅ Carpetas de Java creadas con éxito")
