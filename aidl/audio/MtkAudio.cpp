/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "MtkAudio.h"

namespace aidl::vendor::mediatek::hardware::audio {

MtkAudio::MtkAudio() = default;
MtkAudio::~MtkAudio() = default;

ndk::ScopedAStatus MtkAudio::setAudioParameterChangedCallback(
        const std::shared_ptr<IAudioParameterChangedCallback>& /*callback*/,
        int32_t /*cbkKey*/,
        Result* pResult) {
    if (pResult) {
        *pResult = Result::OK;
    }
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus MtkAudio::clearAudioParameterChangedCallback(
        int32_t /*cbkKey*/,
        Result* pResult) {
    if (pResult) {
        *pResult = Result::OK;
    }
    return ndk::ScopedAStatus::ok();
}

} // namespace aidl::vendor::mediatek::hardware::audio
