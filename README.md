# Temperature Radar 🌡️

A C program that reads and logs daily temperatures to a file, building a persistent register over time.

## About

Since real hardware sensors weren't available, temperatures are generated programmatically within a realistic range (0–45 °C). The project's main goal is to practice C fundamentals: structs, pointers, and file I/O.

In the future I'd like to extend this with actual hardware sensors to capture real temperature data.

## Built With

- **C** — standard libraries only (`stdio.h`, `stdlib.h`)
- **Docker** — for a reproducible build and run environment

## Getting Started

### Prerequisites

- [Docker](https://docs.docker.com/get-docker/) installed on your machine

### Run with Docker

```bash
# Build the image
docker build -t temperature-radar .

# Run the container
docker run --rm temperature-radar
```

Logs are written to a file inside the container. If you want to persist them on your host machine, mount a volume:

```bash
docker run --rm -v $(pwd)/logs:/app/logs temperature-radar
```

## Goals

- [x] Generate and log simulated temperatures
- [x] Persist data to a file
- [ ] Connect real hardware sensors
- [ ] Add timestamps to each log entry
