# CP255v2 - TI-84 Plus CE Color Picker

## Overview
CP255v2 is a color picker application written in C for the TI-84 Plus CE calculator. This project enables users to select and manipulate colors on the calculator's 320x240 pixel color LCD screen, utilizing the `graphx.h` library for rendering. It is an ongoing development effort, building on previous versions (e.g., CP255v1), with the aim of creating a practical tool for color selection and visualization.

## Features
- Interactive color selection interface.
- Real-time color display on the TI-84 Plus CE screen.
- Navigation using the calculator's arrow keys and other standard keys.

## Prerequisites
- **TI-84 Plus CE Calculator** with a compatible operating system.
- **CEdev**: A C development environment for TI-84 Plus CE, available at [CEdev GitHub](https://ce-programming.github.io/toolchain/static/getting-started.html).
- **Clibs**: C libraries for the TI-84 Plus CE calculator (downloadable separately at https://github.com/CE-Programming/libraries/releases).
- **TI-Connect CE**: Software to connect your PC to the TI-84 Plus CE calculator for file transfer, available from the [Texas Instruments website](https://education.ti.com/en/products/computer-software/ti-connect-ce-sw).
- **make**: Required for building the project (included with CEdev).

## Installation

### Setting Up CEdev
1. Install CEdev by following the instructions on the [CEdev GitHub page](https://ce-programming.github.io/toolchain/static/getting-started.html).
2. Verify that the `make` tool is accessible in your command-line environment (e.g., by running `make --version`).

### Building the Project
1. Clone or download this repository to your local machine: