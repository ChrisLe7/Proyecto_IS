# Extracción de requisitos:

## Partes interesadas: 
- Secretario/a.
- Doctor/a.

## Datos que gestiona el [Doctor|Secretario]:

### Paciente:
* Nombre
* Apellidos
* Teléfono
* Sexo
* Fecha de Nacimiento
* Dirección
* Tipo:
    * Mutua
    * Privado

### Tratamiento
* Medicamentos
* Dosis
* Frecuencia
* Fecha de prescripción
* Fecha de finalización

### Historial médico
* Consultas anteriores
* Tratamientos finalizados

### Citas
* Fecha 
* Motivo
* Tratamiento impuesto	

## Requisitos funcionales:
1. Búsqueda de paciente.
2. Mostrar paciente.
3. Añadir paciente.
4. Modificar datos del paciente.
5. Borrar datos del  paciente.
6. Borrar paciente.
7. Mostrar historial médico del paciente.
8. Añadir nuevo historial médico del paciente.
9. Mostrar tratamientos (Fecha de prescripción , Dosis de consumo, fecha de finalización , frecuencia de dosis).
10. Añadir tratamiento.
11. Finalización de tratamiento.
12. Añadir cita. 
13. Cambiar cita. 
14. Cancelar cita .
15. Mostrar agenda de citas diaria.
16. Mostrar agenda de citas completa. 

## Requisitos no funcionales:
* Lenguaje de implementación : C++.
* Interfaz CLI.
* No vulnerable (Protección de datos).
* No mostrar datos personales del paciente cuando queramos mostrar los tratamientos o el historial médico.
* Tener siempre un Backup del historial en caso de pérdida.
* Sistema operativo del sistema: Linux.
