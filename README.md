# Grupo-6-Trainee-Avante

## como iniciar o programa pela primeira vez:
primeiro faça cd ate o diretorio PASTA onde vc quer os trens todos
mkdir /home/SEUUSUARIO/PASTA
cd /home/SEUUSUARIO/PASTA

clone do jeito que preferir ssh ou https

git clone (repositorio)

docker run -it \
  --name trainee-26 \
  --network host \
  --group-add audio \
  --group-add dialout \
  -e DISPLAY=$DISPLAY \
  -e QT_X11_NO_MITSHM=1 \
  -e PULSE_SERVER=unix:/tmp/pulse-socket \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  -v /run/user/$(id -u)/pulse/native:/tmp/pulse-socket \
  -v /dev/snd:/dev/snd \
  -v /home/SEUUSUARIO/PASTA:/home/avant/simulation/avant_ws \
  joaoaugustoc/trainee-26:main \
  bash

## executando normal sem ser primeira instalacao
docker start trainee-26
docker exec -it trainee-26 bash

## verifique se deu certo
cd ~/simulation/starts
./desafio.sh


cd ~/simulation/scripts/avant_ws/src/pkg_avant/pkg_avant
ffmpeg -loglevel quiet -i som1.mp3 -f wav - | paplay
