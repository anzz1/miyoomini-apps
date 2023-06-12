
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

/*
 * Audioserver input pipe in: /tmp/audio_fifo_server
 * Audioserver ioctl pipe in: /tmp/audio_ioctl_req
 * Audioserver ioctl pipe out: /tmp/audio_ioctl_res
 *
 * Default format: raw pcm, signed 16-bit, little endian, stereo, 48000hz (pcm_s16le)
 *
 * ffmpeg -y -i in.wav -f s16le -acodec pcm_s16le -ar 48000 -ac 2 out.raw
 *
 */

int main(int argc, char *argv[]) {
  FILE* fp;
  if (argc > 1) {
    fp = fopen(argv[1], "rb");
  } else {
    freopen(NULL, "rb", stdin);
    fp = stdin;
  }
  if (fp) {
    int fd = open("/tmp/audio_fifo_server", O_RDWR, 438);
    if (fd != -1) {
      int16_t s;
      while (fread(&s, sizeof(s), 1, fp) == 1) write(fd, &s, sizeof(s));
      close(fd);
    }
    if (fp != stdin) fclose(fp);
  }
  return 0;
}
