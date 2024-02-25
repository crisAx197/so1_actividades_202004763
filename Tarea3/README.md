# Ejecucion del script en systemd

1. Dar permiso de ejecucion al script:

chmod +x saludo.sh

2. Crear una instancia en /etc/systemd/system/

[Unit]
After=network.target

[Service]
Type=simple
ExecStart=/home/main/Documentos/SO1/Mag/so1_actividades_202004763/Tarea3/saludo.sh
Restart=always
RestartSec=1

[Install]
WantedBy=multi-user.target

3. Habilitar el servicio

sudo systemctl daemon-reload 
sudo systemctl enable saludo.service
sudo systemctl start saludo.service 

