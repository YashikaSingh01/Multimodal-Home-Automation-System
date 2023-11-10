import whisper

import sounddevice as sd
from scipy.io.wavfile import write

fs = 44100  # Sample rate
seconds = 5  # Duration of recording

print("Start Recording")
myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2)
sd.wait()  # Wait until recording is finished
write('speech.wav', fs, myrecording)  # Save as WAV file
print("Recording Stopped")


model = whisper.load_model('medium')

print("\nProcessing...")
audio = whisper.load_audio("speech.wav")
audio = whisper.pad_or_trim(audio)

mel = whisper.log_mel_spectrogram(audio).to(model.device)

_, probs = model.detect_language(mel)

options = whisper.DecodingOptions(fp16=False)
result = whisper.decode(model, mel, options)

print(type(result.text))

res = model.transcribe('speech.wav')
arr = res['text'].split(' ')

print(arr)
