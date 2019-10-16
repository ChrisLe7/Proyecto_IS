# Mostrar tratamientos del paciente
**ID:** 12

**Descripción:** Se desea visualizar los tratamientos vigentes en un paciente.

**Actores principales:** [Doctor|Secretario].

**Precondiciones:** El paciente se encuentre en el sistema.

**Flujo principal:**
1. El [Doctor|Secretario] desea visualizar los tratamientos de un paciente.
2. El [Doctor|Secretario] introducirá el nombre del paciente a mostrar.
3. El sistema mostrará todos los tratamientos vigentes que tiene el paciente.

**Postcondiciones:** Niguna.

**Flujo alternativo:**

2. a. Si no existe el paciente buscado mandará un mensaje de error.
