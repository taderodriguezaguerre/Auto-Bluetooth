# 🚗 Auto RC Controlado por Bluetooth con App Propia

Este proyecto consiste en el diseño, ensamblaje y programación de un vehículo a control remoto (RC) operado vía Bluetooth. El sistema integra un **Arduino UNO**, electrónica de potencia para el manejo de motores mediante un Motor Shield, luces LED direccionales, y una **aplicación móvil desarrollada a medida** utilizando MIT App Inventor.

## 📱 Demostración
> Foto del proyecto
![Demo del Auto funcionando](https://github.com/taderodriguezaguerre/Auto-Bluetooth/blob/main/auto_bluetooth.jpg)

## ✨ Características Principales
- **Control Inalámbrico:** Comunicación bidireccional mediante módulo Bluetooth (HC-05 / HC-06).
- **App Personalizada (MIT App Inventor):** Interfaz móvil propia diseñada desde cero para enviar comandos de dirección y velocidad de forma intuitiva.
- **Sistema de Iluminación:** Integración de luces LED frontales controlables de forma remota, expandiendo la funcionalidad básica del vehículo.
- **Electrónica Integrada:** Uso de un Motor Shield L293D acoplado directamente al Arduino, optimizando el espacio y reduciendo el cableado.

## 🛠️ Hardware y Componentes Utilizados
- **Microcontrolador:** Arduino UNO
- **Shield de Potencia:** Motor Drive Shield L293D
- **Módulo de Comunicación:** Bluetooth HC-05 / HC-06
- **Actuadores:** Motores DC con motorreductor
- **Extras:** Diodos LED (luces frontales) y resistencias correspondientes
- **Alimentación:** (Detallar acá si usaste baterías 18650, pack de pilas, etc.)

## 🔌 Diagrama de Conexiones
> Próximamente esquema 
![Esquema del circuito]()

## 💻 Software y Lógica
El código fuente está escrito en **C++** utilizando el IDE de Arduino. 

La lógica principal gestiona:
1. La lectura del buffer de entrada por el puerto Serial esperando los comandos de la app móvil.
2. El uso de la librería `AFMotor.h` (o lógica de pines directos) para controlar el sentido y la velocidad de los motores acoplados al L293D.
3. El encendido/apagado de pines digitales específicos para activar los faros LED según las instrucciones recibidas.

## 🚀 Cómo replicar este proyecto
1. Clonar este repositorio.
2. Acoplar el Motor Shield L293D sobre el Arduino UNO y conectar los motores/LEDs a las borneras correspondientes.
3. Desconectar los pines RX y TX del módulo Bluetooth para evitar interferencias al programar.
4. Cargar el archivo `.ino` mediante el Arduino IDE.
5. Reconectar RX/TX, instalar la app generada en el celular, vincular el Bluetooth y testear.
