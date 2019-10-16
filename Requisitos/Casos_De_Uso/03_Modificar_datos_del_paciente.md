# Modificar datos del paciente
**ID:** 03

**Descripción:**  Se desea modificar los datos de un paciente.

**Actores principales:** [Doctor|Secretario].

**Precondiciones:** El paciente se encuentre en el sistema.

**Flujo principal:**

  1. El [Doctor|Secretario] desea modificar los datos de un paciente.
  2. El [Doctor|Secretario] introducirá el nombre del paciente a modificar.
  3. El sistema mostrará todos los campos modificables del mismo, de manera que el [Doctor|Secretario] seleccione uno de ellos.
  4. Una vez elegido el campo, podrá introducir los nuevos datos del mismo.
  5. El sistema actualizará los datos del paciente y mostrará un mensaje de éxito.
    
**Postcondiciones:** Niguna.
    
**Flujo alternativo:**

  2. a. Si no existe el paciente buscado mandará un mensaje de error.

