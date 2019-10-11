# Concertar cita

**ID:** 03

**Descripción:** Se concerta la cita al paciente.

**Actores principales:**  [Doctor|Secretario].

**Precondiciones:** Debe de existir el paciente.

**Flujo principal:**
  1. El [Doctor|Secretario] desea concertar una cita al paciente.
  2. El [Doctor|Secretario] introducirá la fecha y hora de la cita.

**Postcondiciones:** El sistema guardará la cita.

**Flujos alternativos:**

2. a. Si el paciente ya tiene cita registrada el sistema mostrará dos opciones:  
  * No concertar cita.
  * Cambiar cita.
