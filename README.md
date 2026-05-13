# EasyVend (Archive)

This is the original source code for **EasyVend**, an automated vending machine project that won **2nd place** at the **Foka STEAM Fair** in 2023.

## 🚀 Overview
The project bridges the gap between hardware and software by allowing users to pre-order items via a web interface with Telebirr integration.

## 🛠 Tech Stack
* **Hardware:** Arduino (C++) for motor and sensor control.
* **Middleware:** Processing (PDE) used as a bridge to manage Serial data (COM12) and CSV logging.
* **Backend:** Node.js and Express for API handling and payment integration.
* **Frontend:** Vanilla JavaScript, HTML, and CSS for the user ordering interface.

## 📂 Project Structure
* `/arduino`: Firmware for the microcontroller.
* `/processing`: Includes logic for data parsing (`new_paymnet_method.pde`), balance management (`phonenumber.pde`), and timing (`Periodically.pde`).
* `/backend`: Node.js/Express server files.
* `/frontend`: Client-side web application files.

---
*Note: This repository is a technical archive. The code reflects my development skills as of 2023.*
