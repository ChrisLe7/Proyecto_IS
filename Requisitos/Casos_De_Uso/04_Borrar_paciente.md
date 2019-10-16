# Borrar paciente.
**ID:** 04

**Descripción:** Se desea borrar al paciente.

**Actores principales:** [Doctor|Secretario].

**Precondiciones:** El paciente se encuentre en el sistema.

**Flujo principal:**

   1. El [Doctor|Secretario] desea borrar a un paciente.
   2. El [Doctor|Secretario] introducirá el nombre del paciente a borrar.
   3. El sistema mostrará un mensaje para confirmar que se desea borrar al paciente.

**Postcondiciones:** Niguna.

**Flujo alternativo:**

  2.a. Si no existe el paciente buscado mandará un mensaje de error.
