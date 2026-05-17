# Changelog

All notable changes to this project will be documented in this file.

## [v1.0.0] - 2026-05-17

### Added
- Dockerized ESP-IDF development environment
- GitHub Actions CI pipeline for automated builds
- ESP-IDF firmware build integration using `idf.py build`
- Static analysis integration using cppcheck
- Build artifact generation (.bin, .elf, .map)
- Modular project architecture structure (app, bsp, drivers, services, tasks)
- CI-based quality gate for code validation
- Artifact upload system in GitHub Actions

### Infrastructure
- Container-based reproducible build system
- CI/CD pipeline using GitHub Actions
- Consistent build environment between local and CI

### Quality
- cppcheck integration with suppression rules for ESP-IDF compatibility
- Exclusion of build system generated directories
- Static analysis enforced as part of CI pipeline

### Notes
- This is the first stable release of the ESP32 Platform
- Establishes baseline architecture for future firmware development