# Cambiar cita
**ID:** 06

**Descripción:** Se cambia la cita del paciente.

**Actores principales:**  [Doctor|Secretario].

**Precondiciones:** Debe de estar registrada la cita que se desea cambiar.

**Flujo principal:**
  1. El [Doctor|Secretario] desea cambiar la cita del paciente.
  2. El [Doctor|Secretario] introducirá la nueva fecha y hora de la cita.
  
**Postcondiciones:** El sistema actualizará la cita.

**Flujos alternativos:**

2. a. Si ya hay una cita registrada con la nueva fecha y hora el sistema mostrará dos opciones:
* No cambiar cita.
* Volver a introducir la fecha y hora de la cita.
