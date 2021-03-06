/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./tiffdither.codelet__1.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
typedef unsigned int  uint32;
typedef uint32  ttag_t;
typedef uint32  tstrip_t;
typedef uint32  ttile_t;
void  astex_codelet__1(uint32 imagewidth, int threshold, unsigned char *outptr, short *thisptr, short *nextptr, uint32 jmax, int lastline, int bit);
int main(int argc, const char **argv)
{
  uint32  imagewidth = 162u;
  int  threshold = 128;
  unsigned char  *outptr;
  short  *thisptr;
  short  *nextptr;
  uint32  jmax = 161u;
  int  lastline = 0;
  int  bit = 128;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * outptr__region_buffer = (char *) __astex_memalloc(21);
  __astex_write_message("Reading outptr value from %s\n", argv[1]);
  __astex_read_from_file(outptr__region_buffer, 21, codelet_data_file_descriptor);
  outptr = (unsigned char *) (outptr__region_buffer + 0l);
  char * thisptr__region_buffer = (char *) __astex_memalloc(324);
  __astex_write_message("Reading thisptr value from %s\n", argv[1]);
  __astex_read_from_file(thisptr__region_buffer, 324, codelet_data_file_descriptor);
  thisptr = (short *) (thisptr__region_buffer + 0l);
  char * nextptr__region_buffer = (char *) __astex_memalloc(324);
  __astex_write_message("Reading nextptr value from %s\n", argv[1]);
  __astex_read_from_file(nextptr__region_buffer, 324, codelet_data_file_descriptor);
  nextptr = (short *) (nextptr__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__1(imagewidth, threshold, outptr, thisptr, nextptr, jmax, lastline, bit);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}

