/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "SoundTriggerHwStub"

#include "SoundTriggerHw.h"

#include <android-base/logging.h>

namespace aidl::android::hardware::soundtrigger3 {

SoundTriggerHw::SoundTriggerHw() {
    LOG(WARNING) << "Starting stub SoundTriggerHw (vendor soundtrigger3-impl disabled)";
}

SoundTriggerHw::~SoundTriggerHw() = default;

ndk::ScopedAStatus SoundTriggerHw::unsupported() const {
    return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
}

ndk::ScopedAStatus SoundTriggerHw::getProperties(Properties* _aidl_return) {
    if (_aidl_return == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }

    *_aidl_return = Properties{};

    // Common fields we know are present across soundtrigger versions:
    _aidl_return->maxSoundModels = 0;
    _aidl_return->maxKeyPhrases = 0;
    _aidl_return->maxUsers = 0;
    _aidl_return->recognitionModes = 0;
#ifdef __has_member
    // If your compiler supported reflection we could probe, but it doesn't.
    // So do NOT touch any other fields.
#endif

    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus SoundTriggerHw::registerGlobalCallback(
        const std::shared_ptr<ISoundTriggerHwGlobalCallback>& callback) {
    // Store but don't use; keeps framework APIs happy.
    mGlobalCallback = callback;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus SoundTriggerHw::loadSoundModel(
        const SoundModel& /*soundModel*/,
        const std::shared_ptr<ISoundTriggerHwCallback>& /*callback*/,
        int32_t* _aidl_return) {
    if (_aidl_return == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }
    *_aidl_return = -1;
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::loadPhraseSoundModel(
        const PhraseSoundModel& /*soundModel*/,
        const std::shared_ptr<ISoundTriggerHwCallback>& /*callback*/,
        int32_t* _aidl_return) {
    if (_aidl_return == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }
    *_aidl_return = -1;
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::unloadSoundModel(int32_t /*modelHandle*/) {
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::startRecognition(
        int32_t /*modelHandle*/, int32_t /*deviceHandle*/, int32_t /*ioHandle*/,
        const RecognitionConfig& /*config*/) {
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::stopRecognition(int32_t /*modelHandle*/) {
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::forceRecognitionEvent(int32_t /*modelHandle*/) {
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::queryParameter(
        int32_t /*modelHandle*/, ModelParameter /*modelParam*/,
        std::optional<ModelParameterRange>* _aidl_return) {
    if (_aidl_return == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }
    *_aidl_return = std::nullopt;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus SoundTriggerHw::getParameter(
        int32_t /*modelHandle*/, ModelParameter /*modelParam*/,
        int32_t* _aidl_return) {
    if (_aidl_return == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }
    *_aidl_return = 0;
    return unsupported();
}

ndk::ScopedAStatus SoundTriggerHw::setParameter(
        int32_t /*modelHandle*/, ModelParameter /*modelParam*/,
        int32_t /*value*/) {
    return unsupported();
}

} // namespace aidl::android::hardware::soundtrigger3
